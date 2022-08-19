{$R-,S-,Q-,I-,O+}
var
  n,i,d,c,j,s,ans: longint;
  a: array [0..20010] of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=-maxlongint;
  for d:=3 to n do
    if n mod d = 0 then
    begin
      c:=n div d;
      for i:=1 to c do
      begin
        s:=0;
        for j:=0 to d-1 do s:=s+a[i+j*c];
        if s > ans then ans:=s;
      end;
    end;
  writeln(ans);
end.