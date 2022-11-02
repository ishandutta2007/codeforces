{$r-,q-,s-,i-,o+}
const
  mhash=10000019;
  base=100003;
  maxn=100500;
var
  ax,ay,n,m,i,j,x,rev,w,ww:longint;
  res:int64;
  last:array[1..2,0..mhash]of longint;
  g:array[1..2,0..maxn]of int64;
  p,pred:array[1..2,0..maxn]of longint;
  hx,hy:array[0..maxn]of int64;
  kg:array[1..2]of longint;
  function gcd(x,y:longint):longint;
    begin
      while (x>0)and(y>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      gcd:=x+y;
    end;
  procedure add(hh:int64;t,val:longint);
    var
      x,ii:longint;
    begin
      x:=hh mod mhash;
      ii:=last[t][x];
      while (ii>0)do begin
        if (g[t][ii]=hh)then break;
        ii:=pred[t][ii];
      end;
      if (ii=0)then begin
        inc(kg[t]);
        g[t][kg[t]]:=hh;
        p[t][kg[t]]:=0;
        pred[t][kg[t]]:=last[t][x];
        last[t][x]:=kg[t];
        ii:=kg[t];
      end;
      inc(p[t][ii],val);
    end;
  function kol(hh:int64;t:longint):longint;
    var
      x,ii:longint;
    begin
      x:=hh mod mhash;
      ii:=last[t][x];
      while (ii>0)do begin
        if (g[t][ii]=hh)then begin
          kol:=p[t][ii];
          exit;
        end;
        ii:=pred[t][ii];
      end;
      kol:=0;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  read(n,m,w);   
  for i:=1 to maxn do begin
    rev:=0;
    x:=i;
    while (x>0)do begin
      rev:=rev*10+(x mod 10);
      x:=x div 10;
    end;
    x:=gcd(i,rev);
    hx[i]:=int64(i div x)*base+(rev div x);
    hy[i]:=int64(rev div x)*base+(i div x);
  end;
  ww:=0;
  j:=m;
  for i:=1 to m do begin
    rev:=0;
    x:=i;
    while (x>0)do begin
      rev:=rev*10+(x mod 10);
      x:=x div 10;
    end;
    if (i=rev)then ww:=ww+1;
    add(hy[i],2,1);
    if (ww>=w)then begin
      j:=i;
      break;
    end;
  end;    
  res:=1000000000000;
  if (ww>=w)then begin
    res:=j;
    ax:=1;ay:=j;
  end;
  add(hx[1],1,1);
  for i:=2 to n do begin
    ww:=ww+kol(hx[i],2);
    add(hx[i],1,1);
    while (ww-kol(hy[j],1)>=w)do begin
      ww:=ww-kol(hy[j],1);
      add(hy[j],2,-1);
      dec(j);
    end;
    if (ww>=w)and(int64(i)*j<res)then begin
      res:=int64(i)*j;
      ax:=i;
      ay:=j;
    end;
  end;
  if (res=1000000000000)
    then writeln(-1)
    else writeln(ax,' ',ay);
  close(output);close(input);
end.