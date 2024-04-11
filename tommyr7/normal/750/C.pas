var n,i,a,b:longint;
    min,max:int64;
begin
  readln(n);
  min:=-maxlongint;
  max:=maxlongint;
  for i:=1 to n do
  begin
    readln(a,b);
    if (b=2) then
      if (1899<=max) then max:=1899;
	if (b=1) then
	  if (1900>=min) then min:=1900;
	min:=min+a;
	max:=max+a;
  end;
  if (min<=max) then
  begin
    if (max>30000000) then writeln('Infinity')
	else writeln(max);
  end else writeln('Impossible');
end.