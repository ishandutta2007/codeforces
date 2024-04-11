var
  x,cr,ans,n,i,j:longint;
  a:array[0..500500]of longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
  end;
  for i:=1 to 5000 do inc(a[i],a[i-1]);
  ans:=n;
  for i:=1 to 5000 do begin
    j:=2*i;
    if (j>5000)then j:=5000;
    cr:=n-(a[j]-a[i-1]);
    if (cr<ans)then ans:=cr;
  end;
  writeln(ans);
end.