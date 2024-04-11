var n,i,j,lefta,righta,leftb,rightb,now,s1,s2:longint;
	que:array[0..200007,1..2] of longint;
	ch:char;
begin
  readln(n);
  righta:=0;
  righta:=0;
  fillchar(que,sizeof(que),0);
  for i:=1 to n do
  begin
    read(ch);
    if (ch='D') then 
	begin
      inc(righta);
	  que[righta,1]:=i;
    end else 
	begin
	  inc(rightb);
	  que[rightb,2]:=i;
	end;
  end;
  readln;
  lefta:=1;
  leftb:=1;
  now:=0;
  while (lefta<=righta) and (leftb<=rightb) do
  begin
    s1:=que[lefta,1]-now;
    s2:=que[leftb,2]-now;
    if (s1<=0) then s1:=s1+n;
	if (s2<=0) then s2:=s2+n;
    if (s1<s2) then
	begin
	  inc(leftb);
	  now:=que[lefta,1];
	  inc(righta);
	  que[righta,1]:=que[lefta,1];
	  inc(lefta);
	end
	else
	begin
	  inc(lefta);
	  now:=que[leftb,2];
	  inc(rightb);
	  que[rightb,2]:=que[leftb,2];
	  inc(leftb);
	end;
  end;
  if (leftb<=rightb) then writeln('R') else writeln('D');
end.