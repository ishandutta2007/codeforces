var
  ud,j,n,ll,rr,i:longint;
  t,x,y,a:array[0..500500]of longint;
  d:array[0..1111,0..1111]of longint;
  used:array[0..500500]of boolean;
  
  function ok(tx:longint):boolean;
    var
      i,max,j,nom:longint;
    begin
      t[1]:=tx;
      for i:=2 to n do t[i]:=-1;
      for i:=1 to n do used[i]:=false;
      for i:=1 to n do begin
        max:=-1;
        for j:=1 to n do 
          if (not used[j])and(t[j]>max)then begin
            max:=t[j];
            nom:=j;
          end;
        if (max=-1)then break;
        used[nom]:=true;
        for j:=1 to n do 
          if (t[nom]+d[nom][j]>t[j])then t[j]:=t[nom]+d[nom][j];
      end;
      ok:=t[n]<>-1;
    end;

begin
  read(n,ud);
  for i:=2 to n-1 do read(a[i]);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to n do 
    for j:=1 to n do 
      if (i=j)then d[i][j]:=0 else d[i][j]:=a[i]-(abs(x[i]-x[j])+abs(y[i]-y[j]))*ud;
  ll:=0;rr:=1000000000;
  while (ll<rr-1)do 
    if (ok((ll+rr)shr 1))
      then rr:=(ll+rr)shr 1
      else ll:=(ll+rr)shr 1;
  if (ok(ll))then writeln(ll)else writeln(rr);
end.