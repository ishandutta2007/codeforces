{$r-,q-,s-,i-,o+}
var
  q,i,j,n,k:longint;
  a:array[0..100500]of longint;
  used:array[0..100500]of boolean;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  fillchar(used,sizeof(used),false);
  for i:=1 to n do begin
    for j:=1 to n do
      if(not used[j])and(a[j]=0)then begin
        write(j,' ');
        used[j]:=true;
        for q:=1 to j-k do dec(a[q]);
        break;
      end;
  end;
end.