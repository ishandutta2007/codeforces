{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  ss,m,i,j,n,k,kt,res:longint;
  t:array[0..500500]of longint;
  q,fact:array[0..500]of longint;
  was:array[0..500500]of boolean;
  procedure gen(x:longint);
    begin
      if (x<>0)then begin
        inc(kt);t[kt]:=x;
      end;
      if (int64(x)*10>inf)then exit;
      gen(x*10+4);
      gen(x*10+7);
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,k);
  kt:=0;
  gen(0);
  res:=0;
  for i:=1 to kt do
    if (t[i]<n-12)then inc(res);
  m:=n;
  ss:=1;
  fact[0]:=1;
  if (n>13)then begin
     m:=13;
     ss:=n-12;
     for i:=1 to m do fact[i]:=fact[i-1]*i;
  end else begin
    for i:=1 to n do fact[i]:=fact[i-1]*i;
    if (k>fact[n])then begin
      writeln(-1);
      exit;
    end;
  end;
  fillchar(was,sizeof(was),false);
  for i:=1 to m do begin
    j:=1;
    while (true)do begin
      while (was[j])do inc(j);
      if (k>fact[m-i])then begin
        dec(k,fact[m-i]);
        inc(j);
      end else break;
    end;
    was[j]:=true;
    q[i]:=ss+j-1;
  end;
  for i:=1 to kt do
    if (t[i]>=ss)and(t[i]<=n)then
      for j:=1 to kt do
        if (q[t[i]-ss+1]=t[j])then inc(res);
  writeln(res);
  close(output);close(input);
end.