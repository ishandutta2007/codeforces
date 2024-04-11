{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const maxt = 1000000;
      maxn = 200010;
      co = 300;
var
  u,z,j,n,kq,i: longint;
  last,cnt: array [0..maxt+10] of longint;
  pred,s,left,right,pr,ls,a: array [0..maxn] of longint;
  ans,t: array [0..maxn] of int64;

procedure modify(x,v:longint);
begin
  while x <= n do
  begin
    t[x]:=t[x]+v;
    x:=(x or (x-1))+1;
  end;
end;

function findsum(x:longint):int64;
var
  r: int64;
begin
  r:=0;
  while x > 0 do
  begin
    r:=r+t[x];
    x:=x and (x-1);
  end;
  findsum:=r;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,kq);
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(cnt[a[i]]);
  end;
  fillchar(ls,sizeof(ls),0);
  for i:=1 to kq do
  begin
    read(left[i],right[i]);
    ans[i]:=0;
    pr[i]:=ls[left[i]];
    ls[left[i]]:=i;
  end;
  for z:=1 to maxt do
    if cnt[z] > co then
    begin
      s[0]:=0;
      for i:=1 to n do
        if a[i] = z then
        begin
          s[i]:=s[i-1]+1;
          a[i]:=0;
        end
        else s[i]:=s[i-1];
      for i:=1 to kq do
      begin
        u:=s[right[i]]-s[left[i]-1];
        ans[i]:=ans[i]+int64(u)*u*z;
      end;
    end;
  fillchar(last,sizeof(last),0);
  fillchar(t,sizeof(t),0);
  for i:=n downto 1 do
  begin
    if a[i] > 0 then
    begin
      modify(i,a[i]);
      j:=last[a[i]];
      while j > 0 do
      begin
        modify(j,a[i] shl 1);
        j:=pred[j];
      end;
      pred[i]:=last[a[i]];
      last[a[i]]:=i;
    end;
    j:=ls[i];
    while j > 0 do
    begin
      ans[j]:=ans[j]+findsum(right[j]);
      j:=pr[j];
    end;
  end;
  for i:=1 to kq do writeln(ans[i]);
  close(input);
  close(output);
end.