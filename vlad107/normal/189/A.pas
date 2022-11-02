var
  ans,n,a,b,c,i,j,cr:longint;

begin
  read(n,a,b,c);
  ans:=0;
  for i:=0 to n div a do 
    for j:=0 to (n-a*i)div b do
      if ((n-a*i-b*j)mod c=0)then begin
        cr:=i+j+(n-a*i-b*j)div c;
        if (cr>ans)then ans:=cr;
      end;
  writeln(ans);
end.