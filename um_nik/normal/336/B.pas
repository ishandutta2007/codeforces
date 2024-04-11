var r,m,ans:real;
begin
read(m,r);
ans:=r*(2*m*m+2*(m-1)*m*(m+1)/3-2*(m-1)*(m-1)*(2-sqrt(2)))/m/m;
writeln(ans);
end.