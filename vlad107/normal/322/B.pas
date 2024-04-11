var
  cr,i,a,b,c,ans:longint;

begin
  read(a,b,c);
  ans:=0;
  for i:=0 to 100 do 
    if (i<=a)and(i<=b)and(i<=c)then begin
      cr:=i+(a-i)div 3+(b-i)div 3+(c-i)div 3;
      if (cr>ans)then ans:=cr;
    end;
  writeln(ans);
end.