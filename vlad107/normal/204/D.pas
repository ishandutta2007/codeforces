{$r+,q+,s+,i+,o-}
const
  base=1000000007;

var
  kb,kw,f1,f2,g:array[0..1000500]of longint;
  i,n,k:longint;
  ans:int64;
  s:ansistring;

begin
  //assign(input,'input.txt');reset(input);
  readln(n,k);
  readln(s);
  kb[0]:=0;kw[0]:=0;
  for i:=1 to n do begin
    kb[i]:=kb[i-1];
    kw[i]:=kw[i-1];
    if (s[i]='B')then inc(kb[i])else
    if (s[i]='W')then inc(kw[i]);
  end;
  f1[0]:=1;
  for i:=1 to n do begin
    f1[i]:=f1[i-1];
    if (s[i]='X')then f1[i]:=f1[i]+f1[i];
    if (f1[i]>=base)then dec(f1[i],base);
    if (i>k)and(kw[i]-kw[i-k]=0)and(s[i-k]<>'B')then f1[i]:=f1[i]-f1[i-k-1]+base;
    if (i=k)and(kw[i]-kw[i-k]=0)then f1[i]:=f1[i]-1+base;
    if (f1[i]>=base)then dec(f1[i],base);
  end;
  f2[n+1]:=1;
  for i:=n downto 1 do begin
    f2[i]:=f2[i+1];
    if (s[i]='X')then f2[i]:=f2[i]+f2[i];
    if (f2[i]>=base)then dec(f2[i],base);
    if (i+k-1<n)and(kb[i+k-1]-kb[i-1]=0)and(s[i+k]<>'W')then f2[i]:=f2[i]-f2[i+k+1]+base;
    if (i+k-1=n)and(kb[i+k-1]-kb[i-1]=0)then f2[i]:=f2[i]-1+base;
    if (f2[i]>=base)then dec(f2[i],base);
  end;
  g[n+1]:=0;
  for i:=n downto 1 do begin
    g[i]:=g[i+1];
    if (s[i]='X')then g[i]:=g[i]+g[i];
    if (g[i]>=base)then dec(g[i],base);
    if (i+k-1<n)and(kb[i+k-1]-kb[i-1]=0)and(s[i+k]<>'W')then g[i]:=g[i]+f2[i+k+1];
    if (i+k-1=n)and(kb[i+k-1]-kb[i-1]=0)then g[i]:=g[i]+1;
    if (g[i]>=base)then g[i]:=g[i]-base;
  end;
  for i:=k to n do begin
    if (i+k-1>n)then break;
    if (i>k)and(kw[i]-kw[i-k]=0)and(s[i-k]<>'B')then ans:=ans+int64(f1[i-k-1])*g[i+1] mod base;
    if (i=k)and(kw[i]-kw[i-k]=0)then ans:=ans+g[i+1];
    ans:=ans mod base;
  end;
  writeln(ans);
  close(input);
end.