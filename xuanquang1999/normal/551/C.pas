const fi = '';
      fo = '';
      maxN = 100000;
      maxC = round(1e18)+7;
var n, m: longint;
    a, b: array [1..maxN] of longint;

procedure Enter;
var i: longint;
begin
 readln(n, m);
 for i:=1 to n do read(a[i]);
end;

function Check(t: int64): boolean;
var iStu, i: longint;
    c: int64;
begin
 i:=n;
 for iStu:=1 to m do
  begin
   while a[i] = 0 do dec(i);
   c:=t-i;
   while true do
    begin
     while (i > 0) and (a[i] = 0) do dec(i);
     if i = 0 then exit(true);
     if a[i] > c then
      begin
       a[i]:=a[i]-c;
       break;
      end
     else c:=c-a[i];
     dec(i);
    end;
  end;
 exit(false);
end;

procedure Work;
var l, r, res, mid: int64;
begin
 l:=1; r:=maxC; res:=maxC+1;
 while l <= r do
  begin

   mid:=(l+r) div 2;
   b:=a;
   if Check(mid) then
    begin
     if mid < res then res:=mid;
     r:=mid-1;
    end
   else l:=mid+1;
   a:=b;
  end;
 writeln(res);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.