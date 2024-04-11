var
  i,ans,a,b,c,d,n:longint;

begin
  read(a,b,c,d,n);
  for i:=1 to n do 
    if ((i mod a)*(i mod b)*(i mod c)*(i mod d)=0)then inc(ans);
  writeln(ans);    
end.