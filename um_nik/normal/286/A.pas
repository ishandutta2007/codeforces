var n,k,i:integer;
a:array [1..200000] of integer;
begin
readln(n);
if (n mod 4=2) or (n mod 4=3) then writeln(-1) else
  begin
  if n mod 4 =0 then
    begin
    k:=2;
    for i:=1 to n div 4 do
      begin
      a[2*i-1]:=k;
      a[2*i]:=n-k+2;
      k+=2;
      end;
    k:=1;
    for i:=1 to n div 4 do
      begin
      a[n-2*i+2]:=n-k;
      a[n-2*i+1]:=k;
      k+=2;
      end;
    end else
    begin
    a[n div 2+1]:=n div 2+1;
    k:=2;
    for i:=1 to n div 4 do
      begin
      a[2*i-1]:=k;
      a[2*i]:=n-k+2;
      k+=2;
      end;
    k:=1;
    for i:=1 to n div 4 do
      begin
      a[n-2*i+2]:=n-k;
      a[n-2*i+1]:=k;
      k+=2;
      end;
    end;
  for i:=1 to n do write(a[i],' ');
  end;
end.