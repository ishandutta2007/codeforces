{$r-,q-,s-,i-,o+}
{$M 10000000}
const
  INF=1000000000000000000;
var
  res,cr:int64;
  i,j,k,q:longint;
  c1,c2,c3:char;
  c:array[1..10]of char;
  a:array[1..10]of int64;
  function calc(x,y:int64;c:char):int64;
    begin
      if (c='+')then calc:=x+y else calc:=x*y;
    end;
  procedure rec(n:longint);
    var
      ta:array[1..10]of int64;
      q,i,j:longint;
    begin
      if (n=1)then begin
        if (a[1]<res)then res:=a[1];
        exit;
      end;
      for i:=1 to n do
        for j:=1 to n do if (i<>j)then begin
          for q:=1 to n do ta[q]:=a[q];
          a[i]:=calc(a[i],a[j],c[4-n+1]);
          a[j]:=a[n];
          rec(n-1);
          for q:=1 to n do a[q]:=ta[q];
        end;
    end;
begin
  for i:=1 to 4 do read(a[i]);
  readln;
  read(c1,c2,c2,c3,c3);
  c[1]:=c1;c[2]:=c2;c[3]:=c3;
  res:=INF;
  rec(4);
  writeln(res);
end.