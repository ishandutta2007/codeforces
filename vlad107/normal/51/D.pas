var
  n4,m,tmp,n,n1,n2,n3,i:longint;
  ok:boolean;
  a,b:array[1..111111] of longint;

  procedure qs(l,r:longint);
    var
      xx,tmp,i,j:longint;

    begin;
      i:=l;j:=r;
      xx:=b[(l+r)shr 1];
      while (i<=j) do begin
        while (xx>b[i])do inc(i);
        while (xx<b[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

  function good(x:longint):boolean;
    begin
      if (x=0)or(x>n)then begin
        good:=false;
        exit;
      end;
      m:=0;
      for i:=1 to n do
        if (i<>x)then begin
          inc(m);
          b[m]:=a[i];
        end;
      ok:=true;
      for i:=2 to n-1 do begin
        if (b[1]=0)or(b[i-1]=0)then begin
          if not ((b[2]=0)and(b[i-1]=0)and(b[i]=0))then begin
            ok:=false;
            break;
          end;
        end;
        if (b[i]*b[1]<>b[2]*b[i-1])then begin
          ok:=false;
          break;
        end;
      end;
      good:=ok;
    end;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  if (n<3)then begin
    if (a[1]=0)and(a[2]<>0)then begin
      writeln(1);
      exit;
    end;
    writeln(0);
    exit;
  end;
  for i:=1 to n do b[i]:=abs(a[i]);
//  qs(1,n);
  ok:=true;
  n1:=0;n2:=0;n3:=0;
  for i:=2 to n do begin
    if (a[1]=0)or(a[i-1]=0)then begin
      if not ((a[2]=0)and(a[i-1]=0)and(a[i]=0))then begin
        n1:=i;
        n2:=i-1;
        ok:=false;
        continue;
      end;
    end;
    if (a[i]*a[1]<>a[2]*a[i-1])then begin
      if (n1<>0)and(n2<>0)then begin
        n3:=i;
        n4:=i-1;
        continue;
      end;
      n1:=i;
      n2:=i-1;
      ok:=false;
    end;
  end;
  if (ok)then begin
    writeln(0);
    exit;
  end;
  if (good(1))or(good(2))or(good(n1))or(good(n2))then begin
    writeln(1);
    exit;
  end;
  if (good(n3))or(good(n4))then begin
    writeln(1);
    exit;
  end;
  writeln(2);
end.