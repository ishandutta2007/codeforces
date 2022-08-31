{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  l,b,f,n,i,q,v,z,h: longint;
  ans,t,p,s,a: array [0..200010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(l,b,f,n);
  for i:=0 to l do a[i]:=0;
  for i:=0 to l do s[i]:=0;
  for q:=1 to n do
  begin
    read(t[q],p[q]);
    if t[q] = 1 then
    begin
      ans[q]:=-1;
      for v:=1 to l-p[q]+1 do
      begin
        z:=v+p[q]+f-1;
        if z > l then z:=l;
        h:=s[z];
        z:=v-b-1;
        if z < 0 then z:=0;
        h:=h-s[z];
        if h = 0 then
        begin
          ans[q]:=v-1;
          break;
        end;
      end;
      if ans[q] <> -1 then
        for i:=ans[q]+1 to ans[q]+p[q] do a[i]:=1;
      writeln(ans[q]);
    end else
    if ans[p[q]] <> -1 then
      for i:=ans[p[q]]+1 to ans[p[q]]+p[p[q]] do a[i]:=0;
    for i:=1 to l do s[i]:=s[i-1]+a[i];
  end;
  close(input);
  close(output);
end.