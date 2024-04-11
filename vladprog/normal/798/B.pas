var
  n,k,i,j,sum,min:longint;
  s1,s:string;
  a:array[1..50]of longint;
  ok:boolean;

begin
  readln(n);
  readln(s1);
  k:=length(s1);
  fillchar(a,sizeof(a),0);
  for i:=2 to n do
    begin
      readln(s);
      for j:=0 to k do
        begin
          if s1=s
            then break;
          s:=copy(s,2,k-1)+s[1]
        end;
      if j=k
        then
          begin
            writeln(-1);
            halt
          end
        else a[i]:=j
    end;
  min:=0;
  for i:=1 to n do
    inc(min,a[i]);
  for i:=1 to k do
    begin
      if (k mod i)<>0
        then continue;
      ok:=true;
      for j:=i+1 to k do
        if s1[j]<>s1[j-i]
          then ok:=false;
      if not ok
        then continue;
      k:=i;
      break
    end;
  for i:=1 to k do
    begin
      sum:=0;
      for j:=1 to n do
        begin
          a[j]:=(a[j]+1) mod k;
          inc(sum,a[j])
        end;
      if min>sum then
        min:=sum
    end;
  writeln(min)
end.