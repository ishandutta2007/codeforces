const maxN = 1000000;
var n, i, j: longint;
    a: string;
    z: array [1..maxN] of longint;
    
function Check(x: longint): boolean;
var i: longint;
    ok: boolean;
begin
 if x = 0 then exit(false);
 
 ok:=false;
 for i:=x+1 to n-1 do
  if z[i] = x then 
   begin
    ok:=true;
    break;
   end;
 if not ok then exit(false);
 
 writeln(copy(a, 1, x));
 exit(true);
end;
    
begin
 readln(a); n:=length(a);
  
 i:=0;
 z[1]:=0;
 for j:=2 to n do
  begin
   while (i > 0) and (a[i+1] <> a[j]) do i:=z[i];
   if a[i+1] = a[j] then inc(i);
   z[j]:=i;
  end;
  
 if not Check(z[n]) and ((z[n] = 0) or not (Check(z[z[n]]))) then writeln('Just a legend');
end.