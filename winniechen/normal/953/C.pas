Program p1_3_2;
var
 n,a,b,num,cnt,vis:longint;
begin
	Read(n);
	num:=0;
	cnt:=0;
	b:=-1;
	while n>0 do
	begin
		Read(a);
		if vis<>1 then
		begin
			if a<>b then
			begin
				if num<=0 then num:=cnt;
				if num<>cnt then
				begin
					vis:=1;
					Write('NO');
				end;
				cnt:=0;
			end;
			cnt:=cnt+1;
			b:=a;
		end;
		n:=n-1;
	end;
	if num<>cnt then 
	begin
	    if num<>0 then
	    begin
    		if vis=0 then Write('NO');
    		vis:=1;
    	end;
	end;
	if vis=0 then Write('YES');
end.