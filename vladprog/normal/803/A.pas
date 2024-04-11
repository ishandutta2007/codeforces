var
  n,k,i,j:longint;
  a:array[1..100,1..100]of longint;

procedure ans;
var
  i,j:longint;
begin
  for i:=1 to n do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln
    end;
  halt
end;

begin
  read(n,k);
  if sqr(n)<k then
    begin
      writeln(-1);
      halt
    end;
  for i:=1 to n do
    begin
      if k>0 then
        begin
          a[i,i]:=1;
          dec(k)
        end;
      if k=0 then ans;
      for j:=i+1 to n do
        begin
          if k>1 then
            begin
              a[i,j]:=1;
              a[j,i]:=1;
              dec(k,2)
            end;
          if k=0 then ans
        end
    end
end.