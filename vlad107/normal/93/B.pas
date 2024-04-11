{$r-,q-,s-,i-,o+}
const
  eps=1e-10;
var
  i,j,n,w,m:longint;
  tx:extended;
  kg:array[0..111]of longint;
  a:array[0..111]of extended;
  g:array[0..111,0..111]of longint;
  p:array[0..111,0..111]of extended;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,w,m);
  for i:=1 to m do a[i]:=n*w/m;
  j:=1;
  for i:=1 to n do begin 
    if (abs(a[j])<eps)then inc(j);
    if (a[j]-w>-eps)then begin
      inc(kg[j]);g[j][kg[j]]:=i;p[j][kg[j]]:=w;
      a[j]:=a[j]-w;
      continue;
    end;
    inc(kg[j]);g[j][kg[j]]:=i;p[j][kg[j]]:=a[j];
    tx:=w-a[j];    
    a[j]:=0;
    inc(j);
    if (tx>eps)then begin
      if (tx-a[j]>eps)then begin
        writeln('NO');
        exit;
      end;
      inc(kg[j]);g[j][kg[j]]:=i;p[j][kg[j]]:=tx;
      a[j]:=a[j]-tx;
    end;
  end;
  writeln('YES');
  for i:=1 to m do begin
    for j:=1 to kg[i] do write(g[i][j],' ',p[i][j]:0:10,' ');
    writeln;
  end;
  close(output);close(input);
end.