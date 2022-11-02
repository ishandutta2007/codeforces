{$r-,q-,s-,i-,o+}
const 
  a:array[1..29]of longint=(1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12);
  m=500500;
var
  u,qt,ans,i,j,n:longint;
  used:array[0..500500]of boolean;
  
begin
  read(n);
  i:=1;
  while (i*i<=n)do inc(i);
  qt:=n;
  ans:=0;
  i:=2;
  while (i*i<=n)do begin
    if (not used[i])then begin
        j:=i;
        u:=0;
        while (j<=n)do begin
          inc(u);
          if (j<=m)then used[j]:=true;
          if (int64(j)*i>n)then break;
          j:=j*i;
        end;
        dec(qt,u);
        ans:=ans xor a[u];
    end;
    inc(i);
  end;
  if (qt and 1=1)then ans:=ans xor 1;
  if (ans=0)then writeln('Petya')else writeln('Vasya');
end.