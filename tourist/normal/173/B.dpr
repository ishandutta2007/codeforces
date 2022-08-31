{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,e: longint;
  x,d: array [-10010..10010] of longint;
  a: array [0..1010,0..1010] of char;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  fillchar(d,sizeof(d),0);
  i:=1; e:=1;
  x[1]:=1;
  d[1]:=1;
  while i <= e do
  begin
    if x[i] > 0 then
    begin
      for j:=1 to m do
        if (a[x[i],j] = '#') and (d[-j] = 0) then
        begin
          inc(e);
          x[e]:=-j;
          d[-j]:=d[x[i]]+1;
        end;
    end else
    begin
      for j:=1 to n do
        if (a[j,-x[i]] = '#') and (d[j] = 0) then
        begin
          inc(e);
          x[e]:=j;
          d[j]:=d[x[i]]+1;
        end;
    end;
    inc(i);
  end;
  writeln(d[n]-1);
end.