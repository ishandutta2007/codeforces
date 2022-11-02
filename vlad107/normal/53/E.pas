{$r-,q-,s-,i-,o+}
var
  res,n,m,k,i,x,y,mask1,mask2,nm1,nm2:longint;
  ss,ff:array[0..500]of longint;
  f:array[0..1111,0..1111]of longint;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m,k);
  for i:=1 to m do begin
    read(ss[i],ff[i]);
    ff[i+m]:=ss[i];
    ss[i+m]:=ff[i];
  end;
  fillchar(f,sizeof(f),$0);
  m:=m+m;
  for i:=1 to m shr 1 do begin
    mask1:=(1 shl (ss[i]-1))+(1 shl (ff[i]-1));
    inc(f[mask1][mask1]);
  end;
  for mask1:=1 to (1 shl n)-1 do 
    for mask2:=1 to (1 shl n)-1 do if (f[mask1][mask2]>0)then begin
      x:=mask2;
      y:=0;
      while (x>0)do begin
        inc(y);
        x:=x and (x-1);
      end;
      if (f[mask1][mask2]<>1)then f[mask1][mask2]:=f[mask1][mask2]div y;
      for i:=1 to m do begin
        x:=1 shl (ss[i]-1);
        y:=1 shl (ff[i]-1);
        if (mask1 and x=0)then continue;
        if (mask1 and y>0)then continue;
        nm1:=mask1+y;
        nm2:=mask2+y;
        if (nm2 and x>0)then nm2:=nm2-x;
        inc(f[nm1][nm2],f[mask1][mask2]);
      end;
    end;
  res:=0;
  for mask2:=1 to (1 shl n)-1 do begin  
    x:=mask2;
    y:=0;
    while (x>0)do begin
      inc(y);
      x:=x and (x-1);
    end;
    if (y<>k)then continue;
    inc(res,f[(1 shl n)-1][mask2]);
  end;
  writeln(res);
  close(output);close(input);
end.