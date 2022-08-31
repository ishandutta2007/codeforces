{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  p,n,i,ss,ff,dd,cur,r,ans: longint;
  g,a: array [0..110,0..110] of longint;
  kg: array [0..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(kg,sizeof(kg),0);
  for i:=1 to n do
  begin
    read(ss,ff,dd);
    inc(kg[ss]);
    g[ss,kg[ss]]:=ff;
    a[ss,kg[ss]]:=0;
    inc(kg[ff]);
    g[ff,kg[ff]]:=ss;
    a[ff,kg[ff]]:=dd;
  end;
  ans:=maxlongint;
  for r:=1 to 2 do
  begin
    cur:=a[1,r];
    i:=g[1,r]; p:=1;
    while i <> 1 do
      if g[i,1] <> p then
      begin
        inc(cur,a[i,1]);
        p:=i;
        i:=g[i,1];
      end else
      begin
        inc(cur,a[i,2]);
        p:=i;
        i:=g[i,2];
      end;
    if cur < ans then ans:=cur;
  end;
  writeln(ans);
  close(input);
  close(output);
end.