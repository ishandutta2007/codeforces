{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  a,b,k,p:array[0..33]of longint;
  r,i,n,u:longint;
  sum,ans:int64;

  procedure rec(x,q:longint);
    var
      i:longint;
      ta:array[0..33]of longint;
      
    begin
      if (x=0)then begin
        sum:=0;
        for i:=1 to n do sum:=sum+int64(a[i])*k[i];
        if (sum>ans)then ans:=sum;
        exit;
      end;
      if (x and 1=0)then begin
        sum:=0;
        for i:=1 to n do sum:=sum+int64(a[i])*k[i];
        if (sum>ans)then ans:=sum;
      end;
      if (q<>1)then begin
        for i:=1 to n do ta[i]:=a[i];
        for i:=1 to n do a[i]:=a[i] xor b[i];
        rec(x-1,1);
        for i:=1 to n do a[i]:=ta[i];
      end;
      for i:=1 to n do ta[i]:=a[i];
      for i:=1 to n do a[i]:=ta[p[i]]+r;
      rec(x-1,0);
      for i:=1 to n do a[i]:=ta[i];
    end;

begin
  read(n,u,r);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do read(k[i]);
  for i:=1 to n do read(p[i]);
  ans:=-1000000000000000000;
  rec(u,0);
  writeln(ans);
end.