var
  cr,n,d,ans,p9,p10,x:int64;
  i:longint;

begin
  read(n,d);
  ans:=n;
  p9:=0;
  p10:=1;
  for i:=1 to 17 do begin
    p9:=p9*10+9;
    p10:=p10*10;
    x:=(n-p9)div p10;
    cr:=x*p10+p9;
    if (n-d<=cr)and(cr<=n)then ans:=cr;
  end;
  writeln(ans);
end.