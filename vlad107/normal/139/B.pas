const
  inf=1000000000;

var
  min,ans,i,j,n,m,q,u,v:longint;
  a,b,h,hh,ww,c:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i],b[i],h[i]);
  read(m);
  for i:=1 to m do read(ww[i],hh[i],c[i]);
  ans:=0;
  for i:=1 to n do begin
    min:=inf;
    for j:=1 to m do begin
      u:=2*(a[i]+b[i]);
      v:=ww[j] div h[i];
      v:=v*hh[j];
      if (v=0)then continue;
      q:=(u+v-1) div v;
      q:=q*c[j];
      if (q<min)then min:=q;
    end;
    inc(ans,min);
  end;
  writeln(ans);
end.