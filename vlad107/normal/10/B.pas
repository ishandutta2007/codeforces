{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  tt,n,i,j,m,xx,ey,max,sum,cr:longint;
  d,a:array[1..111,1..111]of longint;
begin
  read(tt,n);
  for i:=1 to n do
    for j:=1 to n do d[i][j]:=abs(i-(n shr 1)-1)+abs(j-(n shr 1)-1);
  fillchar(a,sizeof(a),$0);
  while (tt>0)do begin
    dec(tt);
    read(m);
    max:=inf;
    xx:=0;
    ey:=0;
    for i:=1 to n do begin
      sum:=0;
      cr:=0;
      for j:=1 to n do begin
        inc(sum,a[i][j]);
        inc(cr,d[i][j]);
        if (j>m)then dec(sum,a[i][j-m]);
        if (j>m)then dec(cr,d[i][j-m]);
        if (sum>0)then continue;
        if (j<m)then continue;
        if (cr<max) then begin
          max:=cr;
          xx:=i;
          ey:=j;
        end;
      end;
    end;
    if (max=inf)then begin
      writeln(-1);continue;
    end;
    writeln(xx,' ',ey-m+1,' ',ey);
    for j:=ey-m+1 to ey do a[xx][j]:=1;
  end;
end.