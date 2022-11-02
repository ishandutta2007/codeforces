var
  x,ans,n,i,ii,cr:longint;
  f:array[0..500500]of longint;

begin
  read(n);
  fillchar(f,sizeof(f),$0);
  for i:=1 to n do begin
    read(x);
    ii:=2;
    cr:=0;
    while (ii*ii<=x)do begin
      if (x mod ii=0)then begin
        if (f[ii]>cr)then cr:=f[ii];
        if (f[x div ii]>cr)then cr:=f[x div ii];
      end;
      inc(ii);
    end;
    inc(cr);
    ii:=2;
    while (ii*ii<=x)do begin
      if (x mod ii=0)then begin
        if (cr>f[ii])then f[ii]:=cr;
        if (cr>f[x div ii])then f[x div ii]:=cr;
      end;
      inc(ii);
    end;
    if (cr>f[x])then f[x]:=cr;
  end;
  ans:=1;
  for i:=1 to 100000 do 
    if (f[i]>ans)then ans:=f[i];
  writeln(ans);
end.