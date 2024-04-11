{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  s: array [0..20010] of string;
  score,pred,last,ss,ff,first,second,len: array [0..30010] of longint;
  st: string;
  win: array [0..20010] of boolean;
  sq: array [0..33] of string;
  p,num,ll,rr,mid,nn,max,j,cur,sum,m,cf,cs,n,i,ii,jj: longint;
  cw: boolean;

procedure Sort(l,r:longint);
var
  i,j,pp,x,tt: longint;
  xx,tmp: string;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=len[pp]; xx:=s[pp];
  repeat
    while (len[i] < x) or (len[i] = x) and (s[i] < xx) do inc(i);
    while (x < len[j]) or (x = len[j]) and (xx < s[j]) do dec(j);
    if i <= j then
    begin
      tt:=len[i]; len[i]:=len[j]; len[j]:=tt;
      tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(nn);
  n:=0;
  for i:=1 to nn do
  begin
    readln(sq[i]);
    for ii:=1 to length(sq[i]) do
      for jj:=ii to length(sq[i]) do
      begin
        inc(n);
        s[n]:=Copy(sq[i],ii,jj-ii+1);
        len[n]:=jj-ii+1;
      end;
  end;
  inc(n);
  s[n]:='';
  len[n]:=0;
  Sort(1,n);
  ii:=1;
  for i:=2 to n do
    if s[i] <> s[ii] then
    begin
      inc(ii);
      s[ii]:=s[i];
      len[ii]:=len[i];
    end;
  n:=ii;
  for i:=1 to n do
  begin
    max:=0; sum:=0;
    for j:=1 to length(s[i]) do
    begin
      cur:=Ord(s[i,j])-96;
      if cur > max then max:=cur;
      inc(sum,cur);
    end;
    score[i]:=max*sum;
    for j:=1 to nn do
      if Pos(s[i],sq[j]) > 0 then inc(score[i]);
  end;
  fillchar(last,sizeof(last),0);
  m:=0;
  for i:=2 to n do
    for j:=0 to 1 do
    begin
      if j = 0 then st:=Copy(s[i],2,len[i])
      else st:=Copy(s[i],1,len[i]-1);
      num:=0;
      ll:=1; rr:=i;
      while ll < rr do
      begin
        mid:=(ll+rr) shr 1;
        if s[mid] = st then
        begin
          num:=mid;
          break;
        end;
        if (len[mid] < len[i]-1) or (len[mid] = len[i]-1) and (s[mid] < st) then ll:=mid+1
        else rr:=mid-1;
      end;
      if s[ll] = st then num:=ll;
      if num > 0 then
      begin
        inc(m);
        ss[m]:=num;
        ff[m]:=i;
        pred[m]:=last[num];
        last[num]:=m;
      end;
    end;
  for i:=n downto 1 do
  begin
    win[i]:=False;
    first[i]:=0;
    second[i]:=0;
    j:=last[i];
    while j > 0 do
    begin
      p:=ff[j];
      cw:=not win[p];
      cf:=score[p]+second[p];
      cs:=first[p];
      if (cw > win[i]) or (cw = win[i]) and ((cf > first[i]) or (cf = first[i]) and (cs < second[i])) then
      begin
        win[i]:=cw;
        first[i]:=cf;
        second[i]:=cs;
      end;
      j:=pred[j];
    end;
  end;
  if win[1] then writeln('First')
  else writeln('Second');
  writeln(first[1],' ',second[1]);
  close(input);
  close(output);
end.