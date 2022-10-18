{$macro+}
{$ define debug}

var
  q,h,w,i,j,sum:longint;
  s:array[1..600,1..600]of longint;

begin
{$ifdef debug}
  assign(input,'sample.in');
  reset(input);
  assign(output,'sample.out');
  rewrite(output);
{$endif}
  read(q);
  for q:=1 to q do
    begin
      read(h,w);
      for i:=1 to h do
        for j:=1 to w do
          read(s[i,j]);
      sum:=0;
      for i:=1 to w do
        inc(sum,abs(s[1,i]-s[h,i])-abs(s[h div 2,i]-s[h div 2 + 1,i]));
      if sum>0
        then writeln('NO')
        else writeln('YES')
    end
end.