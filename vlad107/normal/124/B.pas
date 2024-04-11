var
  ts:string;
  q,n,k,i,j,q1,q2,tmp,max,min,res,kt:longint;
  p:array[0..500]of longint;
  a:array[0..50]of string;

begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  for i:=1 to k do p[i]:=i;
  res:=1000000000;
  while (true)do begin
    max:=0;min:=1000000000;
    for i:=1 to n do begin
      ts:='';
      for j:=1 to k do ts:=ts+a[i][p[j]];
      val(ts,kt);
      if (kt>max)then max:=kt;if (kt<min)then min:=kt;
    end;
    if (max-min<res)then res:=max-min;

    j:=k-1;
    while (j>0)and(p[j]>p[j+1])do dec(j);
    if (j=0)then break;
    q:=j+1;
    while (q<k)and(p[q+1]>p[j])do inc(q);
    tmp:=p[q];p[q]:=p[j];p[j]:=tmp;
    for q1:=j+1 to k-1 do
      for q2:=j+1 to k-1 do
        if (p[q2]>p[q2+1])then begin
          tmp:=p[q2];p[q2]:=p[q2+1];p[q2+1]:=tmp;
        end;
  end;
  writeln(res);
end.