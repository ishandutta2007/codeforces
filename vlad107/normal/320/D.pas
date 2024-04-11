{$r-,q-,s-,i-,o+}
var
  ans,kt,kt2,x,n,i,j:longint;
  v,next,prev,a,u:array[0..500500]of longint;
  er:array[0..500500]of boolean;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do next[i]:=i+1;
  for i:=1 to n do prev[i]:=i-1;
  kt:=n;
  for i:=1 to n do u[i]:=i;
  while (true)do begin
    kt2:=0;
    for j:=1 to kt do begin
      x:=u[j];
      if (er[x])then continue;
      if (next[x]<=n)and(a[x]>a[next[x]])then begin
        inc(kt2);
        u[kt2]:=x;
        v[kt2]:=next[x];
      end;
    end;
    kt:=kt2;
    if (kt=0)then break;
    for j:=1 to kt2 do begin
      x:=v[j];
      er[x]:=true;
      if (prev[x]>=1)then next[prev[x]]:=next[x];
      if (next[x]<=n)then prev[next[x]]:=prev[x];
    end;
    inc(ans);
  end;
  writeln(ans);
end.