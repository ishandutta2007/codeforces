{$r-,q-,s-,i-,o+}
var
  kk,kv,kh,tmp,res,n,m,k,i,x,y,tx,ty:longint;
  h,pred,size:array[0..1500500]of longint;
  function fs(x:longint):longint;
    begin
      if (pred[x]<>x)
        then fs:=fs(pred[x])
        else fs:=x;
    end;
  procedure down(x:longint);
    begin
      while (x>1)and(h[x]<h[x shr 1])do begin
        tmp:=h[x];h[x]:=h[x shr 1];h[x shr 1]:=tmp;
        x:=x shr 1;
      end;
    end;
  procedure up(x:longint);
    var
      y:longint;
    begin
      while (x+x<=kh)do begin
        y:=x+x;
        if (y<kh)and(h[y+1]<h[y])then inc(y);
        if (h[y]>=h[x])then break;
        tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
        x:=y;
      end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m,k);
  for i:=1 to n do begin
    pred[i]:=i;
    size[i]:=1;
  end;
  for i:=1 to m do begin
    read(x,y);
    tx:=fs(x);
    ty:=fs(y);
    if (tx=ty)then continue;
    if (size[tx]>size[ty])
      then begin
        pred[ty]:=tx;
        inc(size[tx],size[ty]);
      end else begin
        pred[tx]:=ty;
        inc(size[ty],size[tx]);
      end;
  end;
  kk:=0;
  kv:=0;
  kh:=0;
  for i:=1 to n do 
    if (pred[i]=i)then begin
      inc(kk);
      if (k<size[i])then size[i]:=k;
      inc(kv,size[i]);
      inc(kh);
      h[kh]:=size[i];
      down(kh);
    end;
  res:=0;
  
  while (kv<2*(kk-1))do begin  
    inc(res);
    dec(kk);
    x:=h[1];
    h[1]:=h[kh];
    dec(kh);
    up(1);
    y:=h[1];
    h[1]:=h[kh];
    dec(kh);
    up(1);
    dec(kv,x+y);
    inc(x,y);
    if (x>k)then x:=k;
    inc(kv,x);
    inc(kh);
    h[kh]:=x;
    down(kh);
  end;
  writeln(res);
  close(output);close(input);
end.