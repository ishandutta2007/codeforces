const fi = '';
      fo = '';
      maxN = 100000;
var a: array [1..maxN] of longint;
    d: array [0..maxN] of longint;
    n, q: longint;

procedure Enter;
var i, c, t: longint;
begin
 readln(n, q);
 d[0]:=0;
 for i:=1 to n do
  begin
   readln(c, t);
   a[i]:=c*t; d[i]:=d[i-1]+a[i];
  end;
end;

function Find(t: longint): longint;
var l, r, mid, res: longint;
begin
 l:=1; r:=n; res:=-1;
 while l <= r do
  begin
   mid:=(l+r) div 2;
   if d[mid] >= t then
    begin
     res:=mid;
     r:=mid-1;
    end
   else l:=mid+1;
  end;
 exit(res);
end;

procedure Work;
var i, t: longint;
begin
 for i:=1 to q do
  begin
   read(t);
   writeln(Find(t));
  end;
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.