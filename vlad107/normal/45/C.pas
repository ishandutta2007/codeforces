{$r-,q-,s-,i-,o+}
var 
  tx,ty,n,i,kh,kr,x,y:longint;
  s:ansistring;
  rx,ry,prev,next,a,h,hx,hy:array[0..500500]of longint;
  function cmp(x,y:longint):boolean;
    begin
      if (h[x]=h[y])
        then cmp:=hx[x]>hx[y]
        else cmp:=h[x]>h[y];
    end;
  procedure up(x:longint);
    var
      tmp,y:longint;
    begin
      while (x+x<=kh)do begin
        y:=x+x;
        if (y<kh)and(cmp(y,y+1))then inc(y);
        if (cmp(y,x))then break;
        tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
        tmp:=hx[x];hx[x]:=hx[y];hx[y]:=tmp;
        tmp:=hy[x];hy[x]:=hy[y];hy[y]:=tmp;
        x:=y;
      end;
    end;
  procedure down(x:longint);
    var
      tmp:longint;
    begin
      while (x>1)and(cmp(x shr 1,x))do begin
        tmp:=h[x];h[x]:=h[x shr 1];h[x shr 1]:=tmp;
        tmp:=hx[x];hx[x]:=hx[x shr 1];hx[x shr 1]:=tmp;
        tmp:=hy[x];hy[x]:=hy[x shr 1];hy[x shr 1]:=tmp;
        x:=x shr 1;
      end;
    end;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(n);
  readln(s);
  for i:=1 to n do read(a[i]);
  kh:=0;
  for i:=1 to n-1 do 
    if (s[i]<>s[i+1])then begin
      inc(kh);
      h[kh]:=abs(a[i+1]-a[i]);
      hx[kh]:=i;
      hy[kh]:=i+1;
      down(kh);
    end;
  for i:=1 to n do prev[i]:=i-1;
  for i:=1 to n do next[i]:=i+1;
  kr:=0;
  while (kh>0)do begin
    x:=hx[1];
    y:=hy[1];
    h[1]:=h[kh];
    hx[1]:=hx[kh];
    hy[1]:=hy[kh];
    dec(kh);
    up(1);
    if (prev[x]<0)or(prev[y]<0)then continue;
    inc(kr);
    rx[kr]:=x;
    ry[kr]:=y;
    if (prev[x]=0)or(next[y]=n+1)or(prev[prev[x]]<0)or(prev[next[y]]<0)then begin
      prev[x]:=-1;prev[y]:=-1;
      next[x]:=-1;next[y]:=-1;
      continue;
    end;
    tx:=x;
    ty:=y;
    x:=prev[x];
    y:=next[y];
    prev[y]:=x;
    next[x]:=y;
    if (s[x]<>s[y])then begin
      inc(kh);
      h[kh]:=abs(a[y]-a[x]);
      hx[kh]:=x;
      hy[kh]:=y;
      down(kh);
    end;
    prev[tx]:=-1;prev[ty]:=-1;
    next[tx]:=-1;next[ty]:=-1;
  end;
  writeln(kr);
  for i:=1 to kr do writeln(rx[i],' ',ry[i]);
end.