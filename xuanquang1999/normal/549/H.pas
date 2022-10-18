uses math;
const fi = '';
      fo = '';
      maxC = 2e9;
      e = 0.0000000001;
var a, b, c, d: int64;
    i1, i2, i3, i4: longint;
    l, r, mid, res: extended;

procedure Swap(var a, b: int64);
var t: int64;
begin
 t:=a; a:=b; b:=t;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 readln(a, b);
 readln(c, d);
 if a*d < b*c then
  begin
   Swap(a, b);
   Swap(c, d);
  end;

 res:=maxC+1;
 for i1:=-1 to 1 do
  for i2:=-1 to 1 do
   for i3:=-1 to 1 do
    for i4:=-1 to 1 do
     if (i1 <> 0) and (i2 <> 0) and (i3 <> 0) and (i4 <> 0) then
      begin
       l:=0; r:=maxC;
       while r-l > e do
        begin
         mid:=(r+l)/2;
         if (a+mid*i1)*(d+mid*i4) > (b+mid*i2)*(c+mid*i3) then l:=mid+e
         else r:=mid-e;
        end;
       res:=min(mid, res);
      end;

 writeln(res:0:10);

 close(input); close(output);
end.