{$r-,q-,s-,i-,o+}
var
  t:array[0..500500]of int64;
  res:Int64;
  l,r,kt,i,j:longint;
  tmp:int64;
  procedure rec(k:longint;x:int64);
    begin
      if (x>10000000000)then exit;
      if (x<>0)then begin
        inc(kt);t[kt]:=x;
      end;
      if (int64(x)*10+4>10000000000)then exit;
      rec(k+1,x*10+4);
      rec(k+1,x*10+7);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  kt:=0;
  rec(1,0);
  for i:=1 to kt-1 do
    for j:=1 to kt-1 do
      if (t[j]>t[j+1])then begin
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
      end;
  read(l,r);
  res:=0;
  for i:=1 to kt do
    if (l<=t[i])and(r>t[i])then begin
      res:=res+int64(t[i])*(t[i]-l+1);
      l:=t[i]+1;
    end else
     if (l<=t[i])and(r<=t[i])then begin
      res:=res+int64(t[i])*(r-l+1);
      break;
    end;
  writeln(res);
  close(output);close(input);
end.