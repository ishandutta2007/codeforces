uses math;

var
  n,i,ai,bi:longint;
  a,b:array[0..1000000]of longint;
  f:array[0..1000000]of longint;
  r:array[1..200000]of longint;

begin
  read(n);
  for i:=1 to n do
    begin
      read(ai,bi);
      a[ai]:=bi;
      b[bi]:=ai;
      inc(f[ai]);
      dec(f[bi])
    end;
  for i:=1 to 1000000 do
    if f[i]=1 then
      begin
        r[1]:=i;
        break
      end;
  r[2]:=a[0];
  write(r[1],' ',r[2]);
  for i:=3 to n do
    begin
      r[i]:=a[r[i-2]];
      write(' ',r[i])
    end
end.