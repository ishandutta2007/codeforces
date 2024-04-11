{$r-,q-,s-,i-,o+}
const
  maxn=500500;
  bhash=10000019;
  base=200003;
var
  gk,gn,prx,pred,l,r,c,v,rx:array[0..maxn]of longint;
  kr,n,kh,i,x,y,cr,res:longint;
  g:array[0..maxn]of int64;
  last:array[0..bhash+10]of longint;
  procedure find(x:int64;var nom,k:longint);
    var
      y,i:longint;
    begin
      y:=x mod bhash;
      i:=last[y];
      k:=-1;
      while (i>0)do begin
        if (g[i]=x)then begin
          nom:=gn[i];
          k:=gk[i];
          exit;
        end;
        i:=prx[i];
      end;
    end;
  procedure add(x:int64;nom,k:longint);
    var
      y,i:longint;
    begin
      y:=x mod bhash;
      i:=last[y];
      while (i>0)do begin
        if (g[i]=x)then begin
          if (k>gk[i])then begin
            gk[i]:=k;
            gn[i]:=nom;
          end;
          exit;
        end;
        i:=prx[i];
      end;
      inc(kh);
      g[kh]:=x;
      gk[kh]:=k;
      gn[kh]:=nom;
      prx[kh]:=last[y];
      last[y]:=kh;
    end;
begin
  read(n);
  for i:=1 to n do read(v[i],c[i],l[i],r[i]);
  res:=-1;
  fillchar(pred,sizeof(pred),$FF);
  kh:=0;
  for i:=1 to n do begin
    if (l[i]=0)and(r[i]=0)then begin
      if (v[i]>res)then begin
        res:=v[i];
        x:=i;
      end;
      continue;
    end;
    if (l[i]=0)then begin
      add(int64(c[i])*base+r[i],i,v[i]);
      continue;
    end;
    find(int64(l[i])*base+r[i]+c[i],y,cr);
    if (cr<0)then continue;
    pred[i]:=y;
    add(int64(l[i]+c[i])*base+r[i],i,cr+v[i]);
    if (r[i]=0)and(cr+v[i]>res)then begin
      res:=cr+v[i];
      x:=i;
    end;
  end;
  if (res<0)then begin
    writeln(0);
    exit;
  end;
  i:=x;
  kr:=0;
  while (i>0)do begin
    inc(kr);
    rx[kr]:=i;
    i:=pred[i];
  end;
  writeln(kr);
  for i:=kr downto 1 do write(rx[i],' ');
  writeln;
end.