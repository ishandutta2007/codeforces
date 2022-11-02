var
  a:array[0..1000500]of longint;
  it,n,k,i,j:longint;

begin
  read(n,k);
  if (k>(n div 3))then begin
    writeln(-1);
    exit;
  end;
  i:=1;j:=n;
  for it:=1 to k do begin
    if (it=k-1)and(j-i+1=6)then begin
      a[i]:=it;a[i+1]:=it;a[i+2]:=it+1;
      a[i+3]:=it;a[i+4]:=it+1;a[i+5]:=it+1;
      j:=i-1;
      break;
    end;
    a[i]:=it;a[i+1]:=it;a[j]:=it;
    inc(i,2);
    dec(j);
  end;
  for it:=i to j do a[it]:=1;
  for i:=1 to n do write(a[i],' ');
  writeln;
end.