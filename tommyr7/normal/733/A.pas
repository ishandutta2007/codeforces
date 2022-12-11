var s:string;
    i,j,k,ans:longint;
function tryit(x:char):boolean;
begin
  if (x='A') or (x='E') or (x='I') or (x='O') or (x='U') or (x='Y') then exit(true);
  exit(false);
end;
begin
  readln(s);
  ans:=0;
  i:=0;
  if (i<=length(s)) then
  begin
    k:=i;
    for j:=i+1 to length(s) do
		if (tryit(s[j])) then
	    begin
		  if (j-k>ans) then ans:=j-k;
		  k:=j;
		end;
  end;
  if (length(s)+1-k>ans) then ans:=length(s)+1-k;
  writeln(ans);
end.