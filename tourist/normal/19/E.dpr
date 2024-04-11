{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  ss,ec,nn,ff,pz,s,pred,last,pr,p1,p2,vc,x,c,w,pa: array [0..100010] of longint;
  was,good,ans: array [0..100010] of boolean;
  n,m,i,j,e,kc,pw,u,t,ii,ka,qq,kw: longint;
  found: boolean;

procedure findc(v1,v2:longint);
var
  k1,k2,i: longint;
begin
  k1:=0; k2:=0;
  while v1 > 0 do
  begin
    inc(k1);
    p1[k1]:=v1;
    v1:=ss[pr[v1]];
  end;
  while v2 > 0 do
  begin
    inc(k2);
    p2[k2]:=v2;
    v2:=ss[pr[v2]];
  end;
  while p1[k1] = p2[k1] do
    if p1[k1-1] <> p2[k1-1] then break
    else dec(k1);
  kc:=0;
  for i:=1 to k1 do
  begin
    inc(kc);
    vc[kc]:=p1[i];
    ec[kc]:=nn[pr[p1[i]]];
    if i < k1 then good[nn[pr[p1[i]]]]:=False;
  end;
  for i:=k1-1 downto 1 do
  begin
    inc(kc);
    vc[kc]:=p2[i];
    ec[kc-1]:=nn[pr[p2[i]]];
    good[nn[pr[p2[i]]]]:=False;
  end;
  ec[kc]:=nn[j];
  good[ec[kc]]:=False;
  found:=True;
end;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=w[l+random(r-l+1)];
  repeat
    while w[i] < x do inc(i);
    while x < w[j] do dec(j);
    if i <= j then
    begin
      tmp:=w[i]; w[i]:=w[j]; w[j]:=tmp;
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
  read(n,m);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    nn[i+m]:=i;
    nn[i]:=i;
  end;
  ss[0]:=0;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  fillchar(good,sizeof(good),True);
  fillchar(c,sizeof(c),0);
  found:=False;
  kc:=0;
  for ii:=1 to n do
    if not was[ii] then
    begin
      i:=1; e:=1;
      x[1]:=ii;
      pr[ii]:=0;
      c[ii]:=1;
      was[ii]:=True;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if not was[ff[j]] then
          begin
            inc(e);
            x[e]:=ff[j];
            pr[x[e]]:=j;
            was[x[e]]:=True;
            c[x[e]]:=3-c[x[i]];
          end else
          if c[ff[j]] = c[x[i]] then
          begin
            findc(ff[j],x[i]);
            break;
          end;
          j:=pred[j];
        end;
        if found then break;
        inc(i);
      end;
      if found then break;
    end;
  if not found then
  begin
    writeln(m);
    for i:=1 to m-1 do write(i,' ');
    if m > 0 then write(m);
    writeln;
    halt;
  end;
  for i:=1 to kc do
  begin
    vc[i+kc]:=vc[i];
    ec[i+kc]:=ec[i];
  end;
  fillchar(pz,sizeof(pz),0);
  for i:=1 to kc do pz[vc[i]]:=i;
  fillchar(was,sizeof(was),False);
  fillchar(c,sizeof(c),0);
  fillchar(s,sizeof(s),0);
  for ii:=1 to n do
    if not was[ii] then
    begin
      i:=1; e:=1;
      x[1]:=ii;
      was[ii]:=True;
      c[ii]:=1;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if good[nn[j]] then
            if not was[ff[j]] then
            begin
              inc(e);
              x[e]:=ff[j];
              was[x[e]]:=True;
              c[x[e]]:=3-c[x[i]];
            end else
            if c[ff[j]] = c[x[i]] then
            begin
              writeln(0);
              writeln;
              halt;
            end;
          j:=pred[j];
        end;
        inc(i);
      end;
      for qq:=0 to 1 do
      begin
        kw:=0;
        for i:=1 to e do
          if pz[x[i]] > 0 then
          begin
            pw:=(pz[x[i]]+c[x[i]]) and 1;
            inc(kw);
            if pw = qq then w[kw]:=pz[x[i]]
            else w[kw]:=pz[x[i]]+kc;
          end;
        Sort(1,kw);
        u:=0;
        for i:=1 to kw do
        begin
          while (u < kw) and (w[u+1] <= w[i]+kc) do inc(u);
          inc(s[w[i]]);
          dec(s[w[u]]);
        end;
      end;
    end;
  fillchar(ans,sizeof(ans),False);
  for i:=1 to m do
    if not good[i] then ans[i]:=True;
  t:=0;
  for i:=1 to kc+kc do
  begin
    inc(t,s[i]);
    if t > 0 then ans[ec[i]]:=False;
  end;
  ka:=0;
  for i:=1 to m do
    if ans[i] then
    begin
      inc(ka);
      pa[ka]:=i;
    end;
  writeln(ka);
  for i:=1 to ka-1 do write(pa[i],' ');
  if ka > 0 then write(pa[ka]);
  writeln;
  close(input);
  close(output);
end.