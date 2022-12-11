var n,i,j,ans,r:longint;
    a:array[0..300] of longint;
	vis:array[0..300] of boolean;
	flagg:boolean;
function gcd(x,y:longint):longint;
begin
  if (y=0) then exit(x);
  exit(gcd(y,x mod y));
end;
function deal(ans,r:longint):longint;
begin
  if (ans=0) then exit(r);
  exit(int64(ans*r) div gcd(ans,r));
end;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  ans:=0;
  fillchar(vis,sizeof(vis),false);
  for i:=1 to n do
	if not(vis[i]) then
    begin
	  vis[i]:=true;
	  j:=i;r:=0;flagg:=true;
	  while not(vis[j]) or flagg do 
	  begin
	    vis[j]:=true;
	    flagg:=false;
	    j:=a[j];
	    inc(r);
	  end;
	  if (j<>i) then 
	  begin
	    writeln('-1');
	    halt;
	  end;
	  if (r mod 2=0) then r:=r div 2;
	  ans:=deal(ans,r);
	end;
  writeln(ans);
end.