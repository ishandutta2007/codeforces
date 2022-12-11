var k,a,b:int64;
    ans:boolean;
begin
  readln(k,a,b);
  if (a<k) and (b<k) then writeln(-1) else
  begin
    ans:=true;
    if (a mod k<>0) and (b<k) then ans:=false;
	if (b mod k<>0) and (a<k) then ans:=false;
	a:=a div k;b:=b div k;
    if ans then writeln(a+b) else writeln(-1);
  end;
end.