var
  a,b,ans:double;	
  tt:longint;
begin     
  read(tt);
  while (tt>0)do begin
    read(a,b);
    if (b=0)then ans:=1.0 else
    if (a=0)then ans:=0.5 else
    if (4*b>a)then ans:=(a*b+a*a/8)/(2*a*b) else
    ans:=1-b/a;
    writeln(ans:0:10);
    dec(tt);
  end;
end.