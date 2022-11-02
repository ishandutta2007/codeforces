{$r-,q-,s-,i-,o+}
var
  kans,k,mn,mm,tmp,kt,ii,e,ss,ff,nd,md,n,m,i,j:longint;
  ch:char;
  list,name:array[0..1111]of ansistring;
  nom,cost,dead,len:array[0..1111]of longint;
  f,pr:array[0..111,0..50500]of longint;
  used:array[-5..500500]of boolean;
  a1,a2,a3,next,t:array[-5..500500]of longint;
  s,p:ansistring;
  
  function ti(s:ansistring):longint;
    begin
      ti:=((ord(s[1])-48)*10+ord(s[2])-48)*60+(ord(s[4])-48)*10+ord(s[5])-48;
    end;
    
  function it(t:longint):ansistring;
    var
      s0,s1,s2:ansistring;
    begin
      str(1+(t div 1440),s0);
      t:=t mod 1440;
      str(t div 60,s1);while (length(s1)<2)do s1:='0'+s1;
      str(t mod 60,s2);while (length(s2)<2)do s2:='0'+s2;
      it:=s0+' '+s1+':'+s2;
    end;

begin
  //assign(input,'input.txt');reset(input);
  readln(n,m,k);
  for i:=1 to n do readln(list[i]);
  for i:=1 to n do read(len[i]);
  readln;
  for i:=1 to 4 do begin
    readln(s);
    ss:=ti(copy(s,1,pos('-',s)-1));
    ff:=ti(copy(s,pos('-',s)+1,length(s)));
    while (ss<=ff)do begin used[ss]:=true;inc(ss);end;
  end;
  md:=0;
  for i:=1 to m do begin
    s:='';
    read(ch);
    while (ch<>' ')do begin s:=s+ch;read(ch); end;
    name[i]:=s;
    read(nd,ch);
    p:='';
    read(ch);
    while (ch<>' ')do begin p:=p+ch;read(ch); end;
    dead[i]:=(nd-1)*60*24+ti(p);
    if (dead[i]>md)then md:=dead[i];
    readln(cost[i]);
    nom[i]:=i;
  end;
  for i:=1 to m-1 do 
    for j:=1 to m-1 do 
      if (dead[nom[j]]>dead[nom[j+1]])then begin
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  kt:=1;t[1]:=-1;f[0][1]:=0;
  for i:=0 to md do
    if (not used[i mod 1440])then begin
      inc(kt);t[kt]:=i;f[0][kt]:=-1;
    end;
  for i:=1 to kt-1 do next[t[i]]:=t[i+1];
  for i:=0 to m-1 do begin
    for j:=1 to kt do begin
      f[i+1][j]:=f[i][j];
      pr[i+1][j]:=j;
    end;
    e:=nom[i+1];
    ii:=1;
    while (ii<=n)and(list[ii]<>name[e])do inc(ii);
    if (ii>n)then continue;
    mm:=-1;
    for j:=len[ii]+1 to kt do begin
      if (f[i][j-len[ii]]>mm)then begin
        mm:=f[i][j-len[ii]];
        mn:=j-len[ii];
      end;
      if (t[j]<dead[e])and(mm<>-1)and(mm+cost[e]>f[i+1][j])then begin
        f[i+1][j]:=mm+cost[e];
        pr[i+1][j]:=mn;
      end;
    end;
  end;
  mm:=-1;
  for j:=2 to kt do 
    if (f[m][j]>mm)then begin
      mm:=f[m][j];mn:=j;
    end;
  if (mm<0)then begin writeln(0);writeln(0);exit;end;
  writeln(mm);
  kans:=0;
  for i:=m downto 1 do begin
    if (pr[i][mn]=mn)then continue;
    inc(kans);
    a1[kans]:=nom[i];
    a2[kans]:=next[t[pr[i][mn]]];
    a3[kans]:=t[mn];
    mn:=pr[i][mn];
  end;
  writeln(kans);
  for i:=kans downto 1 do writeln(a1[i],' ',it(a2[i]),' ',it(a3[i]));
end.