{$r-,q-,s-,i-,o+}
const
  base=333;
var
  n,tt,i,q,x,cr,y:longint;
  fnom,a,next,fn:array[0..1005000]of longint;
  procedure modify(x,y:longint);
    begin
      a[x]:=y;
      i:=x;
      fn[x]:=0;
      while (i<=n)and(fnom[i]=fnom[x])do begin
        inc(fn[x]);
        inc(i,a[i]);
      end;
      if (i>n)then next[x]:=-1 else next[x]:=i;
      i:=x-1;
      while (i>0)and(fnom[x]=fnom[i])do begin
        if (i+a[i]>n)then begin
          next[i]:=-1;
          fn[i]:=0;
        end else
        if (fnom[i+a[i]]=fnom[i])then begin
          next[i]:=next[i+a[i]];
          fn[i]:=fn[i+a[i]]+1;
        end else begin
          next[i]:=i+a[i];
          fn[i]:=1;
        end;
        dec(i);
      end;
    end;
begin
  read(n,tt);
  for i:=0 to base-1 do fnom[i]:=0;
  for i:=base to n do fnom[i]:=fnom[i-base]+1;
  for i:=1 to n do read(a[i]);
  fillchar(next,sizeof(next),$FF);
  for i:=1 to n do begin
    x:=i;
    fn[i]:=0;
    while (x<=n)and(fnom[x]=fnom[i])do begin
      inc(fn[i]);
      inc(x,a[x]);
    end;
    if (x>n)then next[i]:=-1 else next[i]:=x;
  end;
  while (tt>0)do begin
    dec(tt);
    read(q);
    if (q=1)then begin
      read(x);
      cr:=0;
      while (x+a[x]<=n)do
        if (next[x]<>-1)then begin
          inc(cr,fn[x]);
          x:=next[x];
        end else begin
          inc(x,a[x]);
          inc(cr);
        end;
      writeln(x,' ',cr+1);
    end else begin
      read(x,y);
      modify(x,y);
    end;
  end;
end.