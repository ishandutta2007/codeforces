{$r-,q-,s-,i-,o+}
var
  a1,a2,x,y,ber,kss,i:longint;
  s,t1,t2:ansistring;
  goal,win,missed,nom,n1,n2,k1,k2:array[0..55]of longint;
  ss:array[0..55]of ansistring;
  used:array[0..55]of boolean;
  
  function findnom(s:ansistring):longint;
    var
      i:longint;
      
    begin
      i:=1;
      while (i<=kss)and(s<>ss[i])do inc(i);
      if (i>kss)then begin
        inc(kss);
        ss[kss]:=s;
      end; 
      findnom:=i;
    end;
    
  procedure solve;
    var
      ii,jj,j,tmp,i:longint;
      
    begin
      for i:=1 to 4 do begin
        goal[i]:=0;
        win[i]:=0;
        missed[i]:=0;
      end;
      for i:=1 to 6 do begin
        inc(goal[n1[i]],k1[i]);
        inc(goal[n2[i]],k2[i]);
        inc(missed[n1[i]],k2[i]);
        inc(missed[n2[i]],k1[i]);
        if (k1[i]=k2[i])then begin
          inc(win[n1[i]]);inc(win[n2[i]]);
        end else
        if (k1[i]>k2[i])
          then inc(win[n1[i]],3)
          else inc(win[n2[i]],3);
      end;
      for i:=1 to 4 do nom[i]:=i;
      for ii:=1 to 3 do
        for jj:=1 to 3 do begin
          i:=nom[jj];j:=nom[jj+1];
          if (win[j]>win[i])or((win[j]=win[i])and(goal[j]-missed[j]>goal[i]-missed[i]))or
             ((win[j]=win[i])and(goal[j]-missed[j]=goal[i]-missed[i])and(goal[j]>goal[i]))or
             ((win[j]=win[i])and(goal[j]-missed[j]=goal[i]-missed[i])and(goal[j]=goal[i])and(ss[j]<ss[i]))
               then begin tmp:=nom[jj];nom[jj]:=nom[jj+1];nom[jj+1]:=tmp;end;
        end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  kss:=0;
  for i:=1 to 5 do begin
    readln(s);
    t1:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    t2:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    n1[i]:=findnom(t1);
    n2[i]:=findnom(t2);
    val(copy(s,1,pos(':',s)-1),k1[i]);
    delete(s,1,pos(':',s));
    val(s,k2[i]);
  end;
  ber:=1;
  while (ss[ber]<>'BERLAND')do inc(ber);
  fillchar(used,sizeof(used),false);
  for i:=1 to 5 do
    if (n1[i]=ber)or(n2[i]=ber)then used[n1[i]+n2[i]-ber]:=true;
  used[ber]:=true;
  i:=1;
  while (used[i])do inc(i);
  n1[6]:=ber;n2[6]:=i;
  a1:=-1;a2:=-1;
  for x:=0 to 20 do
    for y:=0 to x-1 do begin
      k1[6]:=x;k2[6]:=y;
      solve;
      if (nom[1]<>ber)and(nom[2]<>ber)then continue;
      if (a1=-1)then begin
        a1:=x;a2:=y;
      end else
      if (x-y<a1-a2)or((x-y=a1-a2)and(y<a2))then begin
        a1:=x;a2:=y;
      end;
    end;
  if (a1=-1)
    then writeln('IMPOSSIBLE')
    else writeln(a1,':',a2);
end.