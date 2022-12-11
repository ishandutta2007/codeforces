#include <bits/stdc++.h>
using namespace std;
 
string encoding;
int decoding[256];
 
string encode(vector<int> vec)
{
	string ans;
	for(auto x: vec)
		ans += encoding[x];
	return ans;
}
 
vector<int> decode(string str)
{
	vector<int> vec;
	for(auto x: str)
		vec.push_back(decoding[x]);
	return vec;
}
 
template <int N>
struct solve
{
	typedef bitset<N*N> bs;
	
	int ind(int a, int b)
	{
		return a * N + b;
	}
	
	bs add(bs x, int a, int b)
	{
		queue<pair<int, int>> q;
		x[ind(a, b)] = 1;
		q.push({ a, b });
		while(!q.empty())
		{
			a = q.front().first; b = q.front().second;
			q.pop();
			for(int k = 0; k < N; k++)
			{
				if(k == a || k == b) continue;
				if(x[ind(k, a)] && !x[ind(k, b)])
				{
					x[ind(k,b)] = 1;
					q.push({k, b});
				}
				else if(x[ind(b, k)] && !x[ind(a, k)])
				{
					x[ind(a,k)] = 1;
					q.push({a, k});
				}
			}
		}
		return x;
	}
	
	int verdict(const bs &x)
	{
		vector<int> bet(N);
		int top = 0, sum_top = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				bet[i] += x[ind(i, j)];
			if(bet[i] >= N / 2)
			{
				top++;
				sum_top += bet[i] - N / 2;
			}
		}
		if(top < N / 2) return 0;
		return sum_top < (N / 2) * (N / 2 - 1) / 2 ? 1 : -1;
	}
	
	unordered_map<bs, bool> mem;
	unordered_set<bs> vis;
	unordered_map<bs, pair<int, int>> best_move_hint;
	vector<int> moves;
	
	pair<int, int> best_move(const bs &x)
	{
		if(!best_move_hint.empty()) 
		{
		    assert(best_move_hint.count(x));
		    return best_move_hint[x];
	    }
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(i != j && !x[ind(i, j)] && !x[ind(j, i)])
				{
					auto y1 = add(x, i, j), y2 = add(x, j, i);
					if(win(y1) && win(y2))
						return { i, j };
				}
		return {-1, -1};
	}
	
	bool win(const bs &x)
	{
		if(!mem.count(x))
		{
			int v = verdict(x);
			if(v == 0) mem[x] = best_move(x).first != -1;
			else mem[x] = v > 0;
		}
		return mem[x];
	}
	
	void visit(const bs &x)
	{
		if(vis.count(x)) return;
		vis.insert(x);
		if(verdict(x)) return;
		auto p = best_move(x);
		moves.push_back(ind(p.first, p.second));
		visit(add(x, p.first, p.second));
		visit(add(x, p.second, p.first));
	}
	
	void add_hint(const vector<int> &h, int &k, bs x = bs())
	{
		if(vis.count(x)) return;
		vis.insert(x);
		if(verdict(x)) return;
		int c = h[k++];
		auto p = make_pair(c / N, c % N);
		best_move_hint[x] = p;
		add_hint(h, k, add(x, p.first, p.second));
		add_hint(h, k, add(x, p.second, p.first));
	}
};
 
map<pair<int, int>, bool> ask_mem;
 
bool ask(int a, int b)
{
    if(a == b) return false;
	if(!ask_mem.count({ a, b }))
	{
		printf("? %d %d\n", a + 1, b + 1);
		fflush(stdout);
		char ans;
		scanf(" %c", &ans);
		ask_mem[{a, b}] = ans == '>';
		ask_mem[{b, a}] = ans == '<';
	}
	return ask_mem[{a, b}];
}
 
typedef solve<6> sol3;
typedef solve<8> sol4;
 
template<int N> void go_with_solve(solve<N> &s)
{
	typename solve<N>::bs state;
	while(s.verdict(state) == 0)
	{
		auto p = s.best_move(state);
		if(!ask(p.first, p.second))
			swap(p.first, p.second);
		state = s.add(state, p.first, p.second);
	}
	assert(s.verdict(state) == 1);
}
 
string hint = "bckCmuDnvEowFpxlthpxL33hpltFL3pxow3pxowhpxFhpgowhpxMVVxNUUFpUVV3lExFplxFhpdlghoppUV3FVfoUfhpVhltEFMVpxnvVpxnvFNUownvUownvUowVpxnvhpx3hpnvV3pxowhpxVhpgowhpxFxEEhpFFVp3nUxFVpnxFVhpfnghoppEF3FdoEdhpFhfnvgowhpxNxMFpMNN3lExFplxFhpdlwxLFpLNNVlDxEoLMMUlDEoFpLMNN3MNVNUUVV3lDhplDhpFF3pVoUhpwxFplxEolEoFpldpV3DUp3VgUlF3pogpVFDpFVdDwxFhpdlxEgodlEgoFhpdlhp3hdlF3hpgohpFhfgnhoppvMN3FNMN3FNeovMModpwVNDLVNDLpwNVeLNVeLpxLMUEMLMUEMFLMhNUVV3NMNNUV3VDELMMUEenhpvNNpxLLFhLNNVdDhegohpwNNpxMMFhMNN3dEdhpFhghhDL3NVMU3NM3FNEMltDEFNpxmuFMowmuMowNpxmuhpx3hpmuN3pxowhpxNhpEFLnvmuLnvNpxmuhpxVhpmuNVpxnvhpxNhpFLnvMowmugowUgomuMUownvgowMgoLnvMowNpxmuhpx3hpmuN3pxowhpxNhpgowhpxVxUNpUVV3mMxNpmxNhpemghoppUV3NVfoUfhpVhmuMNVpxnvNUownvUowVpxnvhpx3hpnvV3pxowhpxVhpgowhpxNxMMhpNNVp3nUxNVpnxNVhpfnghoppMN3NeoMehpNhfnvgowhpxFxEEhpFFNp3mMxFNpmxFNhpemwxDDhpFFNpVmLxDgoEEMoUmLDgoEhpFFNp3mMFNpmFNhpemEFNpVmLFMoUmLMoNpUVV3mLhpmLhpNN3pVoUhpwxFNpmxEMomEFNpmFMomMoNpmepV3LUp3VgUmN3pogpVNLpNVeLwxFNhpemxEMgoemEFNhpemFMgoemMgoNhpemhp3hemN3hpgohpNhfgnhoppvEF3FEF3FdovEEoepwVFDVFDpwFVdDFVdDpxDEUEDEUEDhEFUVV3FdEEhFFLhUV3NVU3NMdnhpvFFpxDDDhFFNhVeLhdgohpwFFpxEEEhFFNh3eMehpFNhghhD3FVEUEF3FCmDnEoFpldpxL33twpL3xgw3xgwlFL3po3pogpxFtpFxdtdopxMVVtvpwNUUtvwUxVtvFV3tEthxFvhxx3FVEUopMVxfvVxfvpNUwfvUwfvUwVxfvhx3fgfvV3hxgwhxVhlEFMVpnVpnFNUonUonUoVpnfpx3vwp3xgwnV3pogpxVvpVxfvfopxFtpwEtwExFtFV3vUthvxFVxvx3FEopFxdtpEwdtEwFxdthx3dgdtF3hxgwhxFhdnopxNtupwMtuwMxNtuFN3tEthxFuhxx3FNEMopvLtuvLxNtuFNVtDthxFuhxxVFNDLpvLwMtuEMUtDtgwEugwwUEMDLvLwMxNtuFN3tEthxFuhxx3FNEMEMFNVtDNUUFVtDxV3twtDhxFF3xVwUhxtghwxEFF3xwhxugwhxxD3VEUhEF3FExVhFfDwxVFNDLxUEMDLUEMVFNDLhFN3hFDLV3FNEMhFNVhFnopNxeupMweuMwNxeuhx3egeuN3hxgwhxNhopLveuLvNxeuhxVefeuNVhxfvhxNhpLvMweugwUefeuMUgwfvgwMgLvMwNxeuhx3egeuN3hxgwhxNhgwhxVefxUUhVefNV3eMehxNfhh3NVMUeuMNVhxfvNUgwfvUgwVhxfvhx3hfvV3hxgwhxVhgwhxNxMMhNNVh3fUfhxNVhghhD3NM3FNEMlDEFNpmFMomMoNpmepx3uwp3xgwmN3pogpxNupNxeuEFLnmLnNpmepxVuvpVxfvmNVpnfpxNupNxeuFLnMomeowUuvoUwfvmMUonfowMuoMweuLnMoNpmepx3uwp3xgwmN3pogpxNupNxeueopxVuvpwUuvwUxVuvNV3uMuhxNvhxx3NVMUopVxfvpUwfvUwVxfvhx3fgfvV3hxgwhxVhmMNVpnNUonUoVpnfpx3vwp3xgwnV3pogpxVvpVxfvfopxNupwMuwMxNuNV3vUuhvxNVxvx3NMopNxeupMweuMwNxeuhx3egeuN3hxgwhxNhenopxFtpwEtwExFtFN3uMthuxFNxux3FEopvDtvDxFtFNVuLthuxFNxuxVFDpvDwEtEMUuLtguwEMwuwUEDvDwExFtFN3uMthuxFNxux3FEEFNVuLFMUuLMUNVuLxV3uwuLhxNN3xVwUhxtguhwxEFNFMMNN3xwwhxxL3VMUhMN3NMuhxxVhNfLwxVFDxUEDUEVFDfFN3LMF3NgMDV3FEgFNVLFVNfLnopFxdtpEwdtEwFxdthx3dgdtF3hxgwhxFhopDvdtDvFxdthxVdfdtFVhxfvhxFhpDvEwdtgwUdfdtEUgwfvgwEgDvEwFxdthx3dgdtF3hxgwhxFhgwhxVdfxUUhVdfFV3dEdhxFfhh3FVEUdtEFVhxfvFUgwfvUgwVhxfvhx3hfvV3hxgwhxVhgwhxFxEEhFFVh3fUfhxFVhghhEF3FCemDfnEgoFhpdlhpL33hdlFL3hpgo3hpgohpFhgohpMVVpNUUFhUVV3dEdhpFhghht3FVEUv3xVwU3xwdlEFMVhpfnVhpfnFNUgofnUgofnUgoVhpfnhp3hfnV3hpgohpVhgohpFpEEhFFVh3fUfhpFVhghhtv3FE3xFwE3xwfngohpNpMFhMNN3dEdhpFhopLFhLNNVdDpEgLMMUdDEgFhLMNN3MNVNUUVV3dDhdDhFF3hVgUhdghopFpEEFF3hghhtvD3FVEU3FE3xFwEv3xVwUwx3xfghhnt3FNEMu3xNwM3xwt3FNEMu3xNwM3xwghotVFNDLuVxNvLVxvtVFNDLuVxNvLVxvhptUEMDLuUwMvLUwvtUEMDLuUwMvLUwvtUEMVFNDLxFN3xFDLV3FNEMxFNVxFuUwMVxNvLxN3xvLV3xNwMxNVxUwVxvxDN3LM3NEMvV3xwxENVLVNDLdlDEFNhpemFMgoemMgoNhpemhp3hemN3hpgohpNhEFLfnemLfnNhpemhpVhemNVhpfnhpNhFLfnMgoemgoUgemMUgofngoMgLfnMgoNhpemhp3hemN3hpgohpNhgohpVpUNhUVV3eMehpNhghhu3NVMUv3xVwU3xwemMNVhpfnNUgofnUgoVhpfnhp3hfnV3hpgohpVhgohpNpMMhNNVh3fUfhpNVhghhuv3NM3xNwM3xwfngohpFpEEhFFNh3eMehpFNhopDDhFFNhVeLpDgEEMgUeLDgEhFFNh3eMehFNhEFNhVeLFMgUeLMgNhUVV3eLheLhNN3hVgUheghopFNpEMEFNFMMNN3hghhuvL3NVMU3NM3xNwMv3xVwUwx3xfghhntu3FE3xFwE3xwtu3FE3xFwE3xwghotuVFDVxFvDVxvtuVFDVxFvDVxvhptuUEDUwEvDUwvtuUEDUwEvDUwvtuUEVFDvFN3LMF3NwMDV3FEwFNVLFVNvLUwEVxFvDxF3xvDV3xFwExFVxUwVxvxEF3FvV3xwxDFVFcCeuDfvEgwFhxdthxL33hdtFL3hxgw3hxgwhxFhgwhxMVVxNUUFhUVV3dEdhxFhghhl3FVEUn3pVoU3podtEFMVhxfvVhxfvFNUgwfvUgwfvUgwVhxfvhx3hfvV3hxgwhxVhgwhxFxEEhFFVh3fUfhxFVhghhln3FE3pFoE3pofvgwhxNxMFhMNN3dEdhxFhwxLFhLNNVdDxEgLMMUdDEgFhLMNN3MNVNUUVV3dDhdDhFF3hVgUhdghwxFxEEFF3hghhlnD3FVEU3FE3pFoEn3pVoUop3pfghhlv3FNEM3FNEMmv3pNoM3pNoMv3po3poghlwVFNDLVFNDLmwVpNnLVpNnLwVpnVpnhlxUEMDLUEMDLmxUoMnLUoMnLxUonUonlUEMVFNDLpFN3pFDLV3FNEMpFNVpFmUoMVpNnLpN3pnLV3pNoMpNVpUoVpnpDN3LM3NEMnV3popENVLVNDLdtDEFNhxeuFMgweuMgwNhxeuhx3heuN3hxgwhxNhEFLfveuLfvNhxeuhxVheuNVhxfvhxNhFLfvMgweugwUgeuMUgwfvgwMgLfvMgwNhxeuhx3heuN3hxgwhxNhgwhxVxUNhUVV3eMehxNhghhm3NVMUn3pVoU3poeuMNVhxfvNUgwfvUgwVhxfvhx3hfvV3hxgwhxVhgwhxNxMMhNNVh3fUfhxNVhghhmn3NM3pNoM3pofvgwhxFxEEhFFNh3eMehxFNhwxDDhFFNhVeLxDgEEMgUeLDgEhFFNh3eMehFNhEFNhVeLFMgUeLMgNhUVV3eLheLhNN3hVgUheghwxFNxEMEFNFMMNN3hghhmnL3NVMU3NM3pNoMn3pVoUop3pfghhlmv3FE3FEv3pFoE3pFoEv3po3poghlmwVFDVFDwVpFnDVpFnDwVpnVpnhlmxUEDUEDxUoEnDUoEnDxUonUonlmUEVFDnFN3LMF3NoMDV3FEoFNVLFVNnLUoEVpFnDpF3pnDV3pFoEpFVpUoVpnpEF3FnV3popDFVFdefghCDEFFL33EFMVVFNUUUVV3DEFNFMMNN3EFLLNNVFLMMULMNN3MNVNUUVV3hghhknvC3xVwU3xVwUC3xw3xwC3pxow3pxownC3pVoU3pVoUopC33pfghhkmuD3xNwM3xNwMD3xw3xwD3pxow3pxowmD3pNoM3pNoMopD33pghkmuEVxNvLVxNvLEVxvVxvEVpxnvVpxnvmEVpNnLVpNnLnpEVVphkmuFUwMvLUwMvLFUwvUwvFUownvUownvmFUoMnLUoMnLnoFUUokmuUwMVxNvLpxN3pxvLV3xNwMpxNVpxUwVxvnxN3LMx3NoMvV3xwoxNVLxVNnLUowVpxnvpx3pnvV3pxowpxVpmUoMVpNnLpN3pnLV3pNoMpNVpnopUVV3poppuvL3NVMU3NM3xNwMv3xVwUwx3xefghhkltL3xFwE3xFwEL3xw3xwL3pxow3pxowlL3pFoE3pFoEopL33pghkltMVxFvDVxFvDMVxvVxvMVpxnvVpxnvlMVpFnDVpFnDnpMVVphkltNUwEvDUwEvDNUwvUwvNUownvUownvlNUoEnDUoEnDnoNUUokltUwEVxFvDpxF3pxvDV3xFwEpxFVpxUwVxvnxF3DEx3FoEvV3xwoxFVDxVFnDUowVpxnvpx3pnvV3pxowpxVplUoEVpFnDpF3pnDV3pFoEpFVpnopUVV3popptvD3FVEU3FE3xFwEv3xVwUwx3xfghkltNxFuCNxuNpxmulNpFmCmpNphkltMwEuCMwuMowmulMoEmCmoMokltMwENxFuCpxF3pxuCN3xFwEpxFNpxMwNxumxF3CEx3FoEuN3xwoxFNCxNFmCMowNpxmupx3pmuN3pxowpxNplMoENpFmCpF3pmCN3pFoEpFNpmopMNN3popptuC3FNEM3FE3xFwEu3xNwMwx3xghkltLvDuCLvuLnvmulLnDmCmnLnkltLvDNxFuCpxFVpxuCNVxFvDpxFNpxLvNxumxFVCDxVFnDuNVxvnxFNCxNFmCLnvNpxmupxVpmuNVpxnvpxNplLnDNpFmCpFVpmCNVpFnDpFNpmnpLNNVpnpptuCVFNDLVFDVxFvDuVxNvLvxVxhkltLvDMwEuCowEUowuCMUwEvDowEMowLvMwumwEUCDwUEnDuMUwvnwEMCwMEmCLnvMowmuowUomuMUownvowMolLnDMoEmCoEUomCMUoEnDoEMomnoLMMUonootuCUEMDLUEDUwEvDuUwMvLvwUwkltLvDMwENxFuCpxF3pxuCN3xFwEpxFNpxowEpxFVFUNxUVV3uMFNxuFNpxmuopwxxUV3NVnwUnpxVpuCMNVxFvDNUwEvDUwEVxFvDpxF3pxvDV3xFwEpxFVpxowEpxFNFMMpxNNVx3vUFNVxvFNVpxnvopwxxMN3NmwMmpxNpLvMwNxumxF3CEx3FoEuN3xwoxFNCxNFmCmwxFVCDxEUCDEUFVCDNV3CMCpFNDpFF3NVMUwxVFnDxUEnDUEVFnDpF3nonDV3pFoEpFVpuMNVxvNUwvUwVxvnxF3DEx3FoEvV3xwoxFVDxVFnDnwxFNCxEMCEMFNCNV3DUCpDFNVFDF3NMwxNFmCxMEmCMENFmCpF3momCN3pFoEpFNpLnvMowNpxmupx3pmuN3pxowpxNpowpxVxUNpUVV3mMmpxNpoppC3NVMUD3FVEU3FEmuMNVpxnvNUownvUowVpxnvpx3pnvV3pxowpxVpowpxNxMMpNNVp3nUnpxNVpoppCD3NM3FNEM3FElLnDMoENpFmCpF3pmCN3pFoEpFNpoEpFVFUNpUVV3mMmpFNpoppu3NVMUv3xVwU3xwmCMNVpFnDNUoEnDUoEVpFnDpF3pnDV3pFoEpFVpoEpFNFMMpNNVp3nUnpFNVpoppuv3NM3xNwM3xwmnopLMNN3MNVNUUVV3popptvD3FVEU3FE3xFwEv3xVwUwx3xnopptuC3FNEM3FE3xFwEu3xNwMwx3xoptuCVFNDLVFDVxFvDuVxNvLvxVxptuCUEMDLUEDUwEvDuUwMvLvwUwtuCUEMVFNDLxFN3xFDLV3FNEMxFNVxFUEVFDvFN3LMF3NwMDV3FEwFNVLFVNvLUwEVxFvDxF3xvDV3xFwExFVxuUwMVxNvLxN3xvLV3xNwMxNVxvwxUVV3xwxxCDL3NVMU3NM3FNEMD3FVEUEF3F";
 
vector<int> better(int k, int n)
{
	vector<int> ans;
	for(int i = 0; i < 2 * n; i++)
		if(i != k && ask(i, k)) ans.push_back(i);
	return ans;
}
 
void tournament(vector<int> v)
{
	if(v.size() == 1) return;
	vector<int> vec;
	for(int i = 0; i < v.size(); i += 2)
	{
		if(i + 1 == v.size()) vec.push_back(v[i]);
		else
		{
			int a = v[i], b = v[i+1];
			vec.push_back(ask(a, b) ? b : a);
		}
	}
	tournament(vec);
}
 
void go(int n)
{
	vector<int> win, lose;
	for(int i = 0; i < n; i++)
	{
		int a = i + i, b = a + 1;
		if(!ask(a, b))
			swap(a, b);
		win.push_back(a);
		lose.push_back(b);
	}
	sort(lose.begin(), lose.end(), ask);
	reverse(lose.begin(), lose.end());
	vector<int> p;
	for(auto x: lose)
	{
		auto b = better(x, n);
		if(b.size() == n || b.size() == n - 1)
			return;
		if(b.size() == n + 1)
		{
		    tournament(b);
		    return;
		}
		if(b.size() < n)
		{
			set<int> st(p.begin(), p.end());
			for(auto y: b)
				st.erase(y);
			p = vector<int>(st.begin(), st.end());
			assert(b.size() + p.size() >= n);
			sort(p.begin(), p.end(), ask);
			return;
		}
		p = b;
	}
}
 
int main()
{
	for(char c = 'a'; c <= 'z'; c++)
		encoding += c;
	for(char c = 'A'; c <= 'Z'; c++)
		encoding += c;
	for(char c = '0'; c <= '9'; c++)
		encoding += c;
	encoding += "-_";
	for(int i = 0; i < encoding.size(); i++)
		decoding[encoding[i]] = i;
	sol3 s3;
	sol4 s4;
	int k = 0;
	s4.add_hint(decode(hint), k);
	assert(k == hint.size());
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
		if(n == 3)
			go_with_solve(s3);
		else if(n == 4)
			go_with_solve(s4);
		else go(n);
		ask_mem.clear();
		puts("!");
		fflush(stdout);
	}
}