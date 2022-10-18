{$macro+}
{$define free}

const
  fi=1;
  la=200000;

var
  n,k,q,i,l,r:longint;
  a:array[fi-1..la+1]of longint;

begin
  read(n,k,q);
  {$ifdef free}
  fillchar(a,sizeof(a),0);
  {$endif}
  for i:=1 to n do
    begin
      read(l,r);
      inc(a[l]);
      dec(a[r+1])
    end;
  for i:=fi to la do
    inc(a[i],a[i-1]);
  for i:=fi to la do
    if a[i]>=k
      then a[i]:=1
      else a[i]:=0;
  for i:=fi to la do
    inc(a[i],a[i-1]);
  for i:=1 to q do
    begin
      read(l,r);
      writeln(a[r]-a[l-1])
    end
end.