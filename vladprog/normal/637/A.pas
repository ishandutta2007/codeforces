var
  n,i,a,m,id:longint;
  k:array[1..1000000]of longint;

begin
  read(n);
  fillchar(k,sizeof(a),0);
  m:=0;
  for i:=1 to n do
    begin
      read(a);
      inc(k[a]);
      if m<k[a] then
        begin
          m:=k[a];
          id:=a
        end
    end;
  writeln(id)
end.