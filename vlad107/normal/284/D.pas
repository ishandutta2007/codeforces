{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  t:int64;
  n,i:longint;
  a:array[0..500500]of longint;
  f:array[0..500500]of int64;

  function dfs(X:longint):int64;
    var
      q:longint;
      e,o:int64;
    begin
      if (x<2)or(x>n)then begin
        if (x=1)then dfs:=-1 else dfs:=0;
        exit;
      end;
      if (f[x]=-2)then f[x]:=-1;
      if (f[x]<>-3)then begin
        dfs:=f[x];
        exit;
      end;
      if (x-a[x]<1)then begin
        f[x]:=a[x];
        dfs:=f[x];
        exit;
      end;
      q:=x-a[x]+a[x-a[x]];
      e:=a[x]+a[x-a[x]];
      f[x]:=-2;
      o:=dfs(q);
      if (f[x]<>-1)then begin
        f[x]:=o;
        if (o<>-1)then f[x]:=f[x]+e;
      end;
      dfs:=f[x];
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=2 to n do read(a[i]);
  for i:=1 to n do f[i]:=-3;
  for i:=2 to n do begin
    dfs(i);
    t:=f[i];
    if (t<>-1)then t:=t+i-1;
    writeln(t);
  end;
end.