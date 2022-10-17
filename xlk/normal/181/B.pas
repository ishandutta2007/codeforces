var x,y:array[1..3000]of longint;
var c:array[-2000..2000,-2000..2000]of byte;
var i,j,z,n:longint;
begin
	read(n);
	for i:=1 to n do
	begin
		read(x[i],y[i]);
		c[2*x[i]][2*y[i]]:=1;
	end;
	for i:=1 to n do
		for j:=i+1 to n do
			inc(z,c[x[i]+x[j],y[i]+y[j]]);
	write(z);
end.