var n,i:longint;
    max,sum:int64;
    a:array[0..107] of int64;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  max:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    if (a[i]>max) then max:=a[i];
  end;
  sum:=0;
  for i:=1 to n do
	sum:=sum+max-a[i];
  writeln(sum);
end.