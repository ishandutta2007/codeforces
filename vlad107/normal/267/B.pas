
{$M 10000000}
var
  ft,st,cu,ct,x,kg,ii,qb,qe,n,i:longint;
  used:array[0..500500]of boolean;
  u,t,p,q,last,pred,g,ss,ff,deg:array[0..500500]of longint;
  
  procedure dfs(x:longint);
    var
      ii:longint;
      
    begin
      ii:=last[x];
      while (ii>0)do begin
        if (not used[p[ii]])then begin
          used[p[ii]]:=true;
          dfs(g[ii]);
        end;
        ii:=pred[ii];
      end;
      inc(cu);
      u[cu]:=x;
    end;
     
  procedure add(x,y:longint);
    var
      i:longint;
      
    begin
      for i:=1 to n do begin
        if (used[i])then continue;
        if ((ss[i]=x)and(ff[i]=y))then begin
          writeln(i,' +');
          used[i]:=true;
          exit;
        end else 
        if ((ss[i]=y)and(ff[i]=x))then begin
          writeln(i,' -');
          used[i]:=true;
          exit;
        end;
      end;
    end;

begin
  read(n);
  for i:=0 to 6 do deg[i]:=0;
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do begin
    read(ss[i],ff[i]);
    inc(deg[ss[i]]);
    inc(deg[ff[i]]);
  end;
  if (n=1)then begin
    writeln('1 +');
    exit;
  end;
  ct:=0;
  for i:=0 to 6 do 
    if (deg[i] and 1=1)then begin
      inc(ct);
      t[ct]:=i;
    end;
  if (ct>2)then begin
    writeln('No solution');
    exit;
  end;
  if (ct=2)then begin
    inc(n);
    ss[n]:=t[1];
    ff[n]:=t[2];
  end;
  for i:=1 to n do begin
    inc(kg);g[kg]:=ff[i];p[kg]:=i;pred[kg]:=last[ss[i]];last[ss[i]]:=kg;
    inc(kg);g[kg]:=ss[i];p[kg]:=i;pred[kg]:=last[ff[i]];last[ff[i]]:=kg;  
  end;
  qb:=0;qe:=1;
  q[1]:=ss[1];
  fillchar(Used,sizeof(used),false);
  used[ss[1]]:=true;
  while (qb<qe)do begin
    inc(qb);
    x:=q[qb];
    ii:=last[x];
    while (ii>0)do begin
      if (not used[g[ii]])then begin
        used[g[ii]]:=true;
        inc(qe);
        q[qe]:=g[ii];
      end;
      ii:=pred[ii];
    end;
  end;
  for i:=1 to n do 
    if (not used[ss[i]])or(not used[ff[i]])then begin
      writeln('No solution');
      exit;
    end;
  fillchar(used,sizeof(used),false);
  dfs(ss[1]);
  dec(cu);
  fillchar(used,sizeof(used),false);
  for i:=1 to cu do 
    if ((u[i]=ss[n])and(u[(i mod cu)+1]=ff[n]))or
        ((u[i]=ff[n])and(u[(i mod cu)+1]=ss[n]))then begin
          st:=i+1;
          ft:=i;
          if (ct=0)then add(u[i],u[i+1]);
          break;
        end;
  while (st<>ft)do begin
    i:=(st mod cu)+1;
    add(u[st],u[i]);
    st:=i;
  end;
end.