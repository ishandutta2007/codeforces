var n,m,i,j,t,k,r,tot:longint;
    a:array[0..50,0..50] of longint;
    x:array[0..50] of longint;
    flag:boolean;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
  begin
    for j:=1 to m do
      read(a[i,j]);
    readln;
  end;
  fillchar(x,sizeof(x),0);
  for i:=1 to m do
    x[i]:=i;
  for i:=1 to m-1 do
    for j:=i+1 to m do
    begin
      t:=x[i];
      x[i]:=x[j];
      x[j]:=t;
      flag:=true;
      for k:=1 to n do
      begin
        tot:=0;
        for r:=1 to m do
          if (a[k,r]<>x[r]) then inc(tot);
        if (tot<>2) and (tot<>0) then flag:=false;
      end;
      if flag then
      begin
        writeln('YES');
        halt;
      end;
      t:=x[i];
      x[i]:=x[j];
      x[j]:=t;
    end;
  flag:=true;
  for k:=1 to n do
  begin
    tot:=0;
    for r:=1 to m do
      if (a[k,r]<>x[r]) then inc(tot);
    if (tot<>2) and (tot<>0) then flag:=false;
  end;
  if flag then writeln('YES') else writeln('NO');
end.